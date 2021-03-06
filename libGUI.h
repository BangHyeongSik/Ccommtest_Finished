#include <stdio.h>
#include <string.h>
#include <Windows.h>

#include "libFile.h"

typedef char* string;

string* lastElement[20];

void print_error(const char* context)
{
	DWORD error_code = GetLastError();
	char buffer[256];
	DWORD size = FormatMessageA(
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_MAX_WIDTH_MASK,
		NULL, error_code, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US),
		buffer, sizeof(buffer), NULL);
	if (size == 0) { buffer[0] = 0; }
	fprintf(stderr, "%s: %s\n", context, buffer);
}

void defaultGUI(char* title, char** contents, int length) {
	int i, empty = 44 - strlen(title), flag = empty % 2;

	printf("忙");
	for (i = 0; i < (empty - flag) / 2; i++) {
		printf("式");
	}
	printf("[ %s", title);
	if (flag == 1) {
		printf(" ");
	}
	printf(" ]");
	for (i = 0; i < (empty - flag) / 2; i++) {
		printf("式");
	}
	printf("忖\n");

	for (i = 0; i < length; i++) {
		printf("弛 %02d. %-42s 弛\n", i + 1, contents[i]);
	}
	printf("弛 00. 給嬴陛晦                                   弛\n");

	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
}

void loading(int isSuccess) {
	system("cls");
	printf("\n");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                   Loading.                     弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("\n");
	Sleep(1000);
	system("cls");
	printf("\n");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                   Loading..                    弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("\n");
	Sleep(1000);
	system("cls");
	printf("\n");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                   Loading...                   弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("\n");
	Sleep(1000);
	if (isSuccess == 1) {
		system("cls");
		printf("\n");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                   Success!                     弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("\n");
	}
	else if (isSuccess == 0) {
		system("cls");
		printf("\n");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                   Failed..                     弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("\n");
	}
}

char getLastValue(int num) {
	return dirDB[num].isLast;
}

int getTitle(int num, string* returnValue) {

	int stair = 0, result = 0;
	int i = 0;
	int point;
	while (num != 0) {
		point = num % 10;
		num /= 10;
		for (; i < dirDB_len; i++) {
			if (dirDB[i].num == stair) {
				point -= 1;
				if (point == 0) {
					result = i;
					break;
				}
			}
		}
		stair += 1;
	}

	*returnValue = dirDB[result].element;
	
	return result;
}

int getContents(int num, string* returnValue) {

	int stair = 0, result = 0;
	int i = 0, count = 0;
	int point;
	
	while (num != 0) {
		point = num % 10;
		num /= 10;
		for (; i < dirDB_len; i++) {
			if (dirDB[i].num == stair) {
				point -= 1;
				if (point == 0) {
					result = i;
					break;
				}
			}
		}
		stair += 1;
	}

	result += 1;
	i = result;
	while (stair <= dirDB[i].num && i < dirDB_len) {
		if (stair == dirDB[i].num) {
			*returnValue = dirDB[i].element;
			lastElement[count] = dirDB[i].element;
			count += 1;
			returnValue += 1;
		}
		i++;
	}

	return count;
}

int showGUI(int num) {
	string title = { 0 };
	string contents[100] = { 0 };
	int length = 0, lineNumber = 0;
	int returnValue = 0;
	char isLast = 'F';
	lineNumber = getTitle(num, &title);
	length = getContents(num, contents);
	defaultGUI(title, contents, length);

	isLast = dirDB[lineNumber].isLast;

	do {
		if (isLast == 'F') {
			printf("檜翕й ?飛橉? 幗が擊 摹鷗п輿撮蹂 : ");
			scanf_s("%d", &returnValue);
		}
		else {
			printf("滲唳й だ塭嘐攪曖 廓?ㄧ? 摹鷗п輿撮蹂 : ");
			scanf_s("%d", &returnValue);
		}

		if (returnValue < 0 || returnValue > length) {
			printf("薑鼻瞳檣 廓?ㄧ? 殮溘п輿撮蹂.\n");
		}
	} while (returnValue < 0 || returnValue > length);

	if (isLast == 'T') {
		returnValue = -returnValue;
	}
	

	return returnValue;
}

char* sendMapElement(int number) {
	return getMapNumber(lastElement[number]);
}