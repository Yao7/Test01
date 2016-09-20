# include <iostream>
#include <string.h>
using namespace std;


char *strcpy(char *dst, const char *src)
{
	int i = 0;
	int a = strlen(dst);
	int b = strlen(src);
	int len = (a > b ? a : b) + 1;
	char ch[len];
	for(i=0; i<len; i++) {
		dst[i] = src[i];
	}
}

int *memcpy(void *dest, void *src, unsigned int count)
{

}

void deleteBlank()
{
	string s;
	getline(cin, s);
	int len = sizeof(s);
	char ch[len];
	for (int i=0; i>len; i++) {
		for (char c : s) {
			ch[i] = c;
		}
	}
	for (int i=len; i>0; i--) {
		if (ch[i] == '\0' || ch[i] == '\t') {
			--len;
		}
		else {

		}
	}
	for (int i=0; i<len; i++) {
		cout << ch[i];
	}
	cout << endl;
}


int main()
{
	char s1[] = "hello";
	char s2[] = "world hello";
	strcpy(s1, s2);
	cout << s1 << endl;
	deleteBlank();
}