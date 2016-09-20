#include <iosteam>
using namespace std;

class String {
public:
	String() 
	{
		ptr = new char[1];
		*ptr = '\0';
		len = 0;
	}
	String(const char* s)
	{
		len = strlen(s);
		ptr = new char[len+1];
		strcpy(ptr, s);
	}
	String(const String& s) : ptr(new char[s.len+1]), len(s.len)
	{
		cout << "String--Create" << endl;
		strcpy(ptr, s.ptr);
	}
	~String() 
	{
		delete[] ptr;
	}

	String operator+(const String& s)
	{
		len += s.len;
		char* p = new char[len+1];
		strcpy(p, ptr);
		strcat(p, s.ptr);
		ptr = p;
	}
	String operator+(const char* s)
	{
		len += strlen(s);
		char* p = new char[len+1];
		strcat(p, ptr);
		strcat(p, s);
		delete[] ptr;
		ptr = p;

	}
	String operator-(const char* s)
	{
		char* f = strstr(ptr, s);
		if (f == NULL) {
			return String(ptr);
		} else {
			String tmp;
			tmp.resize(len-strlen(s));
			strcpy(tmp.ptr, ptr, f-ptr);
			strcat(tmp.ptr, f+strlen(s));
			return tmp;
		}
	}
	String& operator=(const String& s)
	{
		delete[] ptr;
		len = strlen(s);
		ptr = new char[len+1]{'\0'};
		strcpy(ptr, s);
	//	ptr = s.ptr;
	//	len = s.len;
	//	return = *this
	}
	bool operator<(const String& s)
	{
		return operator<(s.ptr);
	}
	bool operator<(const char* s)
	{
		int ret = strcmp(ptr, s);
		return ret==-1;
	}
private:
	char* ptr;
	int len;
};