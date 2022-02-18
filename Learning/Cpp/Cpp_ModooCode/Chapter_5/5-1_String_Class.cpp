//Assign,Reserve,Insert,Erase,Find,Length,Capacity,At 구현

#include <iostream>
#include <string.h> //strlen 함수, 헤더 추가 안하고 직접 strlen 만들어도 됨

class MyString
{
private:
	char* string_content; //문자열 데이터를 가리키는 포인터
	int string_length; //문자열 길이
	int memory_capacity; //현재 할당된 용량
	
public:
	//문자 하나로 생성
	MyString(char c);
	
	explicit MyString(int capacity);
	
	//문자열로부터 생성
	MyString(const char* str);
	
	//복사 생성자
	MyString(const MyString& str);
	
	~MyString();
	
	int length() const;
	int capacity() const;
	void reserve(int size);
	
	void print() const;
	void println() const;
	
	MyString& assign(const MyString& str);
	MyString& assign(const char* str);
	
	//특정 위치의 문자를 리턴하는 함수
	char at(int i) const;
	
	MyString& insert(int loc, const MyString& str);
	MyString& insert(int loc, const char* str);
	MyString& insert(int loc, char c);
	
	MyString& erase(int loc, int num);
	
	int find(int find_from, MyString& str) const;
	int find(int find_from, const char* str) const;
	int find(int find_from, char c) const;
	
	int compare(const MyString& str) const;
	bool operator==(MyString& str);
};

MyString::MyString(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	memory_capacity = 1;
	string_length = 1;
}

MyString::MyString(const char* str)
{
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];
	
	for(int i=0;i!=string_length;i++)
		string_content[i] = str[i];
}

MyString::MyString(const MyString& str)
{
	string_length = str.string_length;
	memory_capacity = str.string_length;
	string_content = new char[string_length];
	
	for(int i=0; i!= string_length; i++)
		string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }
int MyString::length() const { return string_length; }

void MyString::print() const{
	for(int i=0;i!=string_length;i++)
		std::cout << string_content;
}

void MyString::println() const
{
	for(int i=0;i!=string_length;i++)
		std::cout << string_content[i];
	
	std::cout<<'\n';
}

MyString& MyString::assign(const MyString& str)
{
	if(str.string_length > memory_capacity)
	{
		delete[] string_content;
		
		string_content = new char[str.string_length];
		memory_capacity = str.string_length;
	}
	
	for(int i=0; i!=str.string_length; i++)
		string_content[i] = str.string_content[i];
	
	//str.string_length + 1 ~ string_length 부분은 초기화 안해도 됨
	//거기까지는 읽어들이지 않음
	
	string_length = str.string_length;
	
	return *this;
}

MyString& MyString::assign(const char* str)
{
	int str_length = strlen(str);
	if (str_length > memory_capacity)
	{
		//그러면 다시 할당을 해준다
		delete[] string_content;
		
		string_content = new char[str_length];
		memory_capacity = str_length;
	}
	for(int i=0; i!=str_length; i++)
		string_content[i] = str[i];
	
	string_length = str_length;
	
	return *this;
}

int MyString::capacity() const { return memory_capacity; }

void MyString::reserve(int size)
{
	if(size>memory_capacity)
	{
		char* prev_string_content = string_content;
		
		string_content = new char[size];
		memory_capacity = size;
		
		for(int i=0; i!= string_length; i++)
			string_content[i] = prev_string_content[i];
		
		delete[] prev_string_content;
	}
	//reserve size가 현재 capacity 보다 작으면 아무것도 안해도 됨
}

char MyString::at(int i) const
{
	if( i>= string_length || i<0)
		return 0;
	else
		return string_content[i];
}

MyString& MyString::insert(int loc, const MyString& str)
{
	//i의 위치 바로 앞에 문자를 삽입, 예를 들어 abc라는 문자열에
	//insert(1n "d")를 하게 되면 adbc가 된다.
	
	//범위를 벗어나는 입력에 대해서는 삽입을 수행 X
	if(loc < 0 || loc > string_length)
		return *this;
	
	if(string_length + str.string_length > memory_capacity)
	{
		//새롭게 동적으로 할당 해야 함
		if(memory_capacity * 2 > string_length + str.string_length)
			memory_capacity *= 2;
		else
			memory_capacity = string_length + str.string_length;
		
		char* prev_string_content = string_content;
		string_content = new char[memory_capacity];
		
		int i;
		//일단 insert 되는 부분 직전까지 내용 복사.
		for(i=0; i<loc; i++)
			string_content[i] = prev_string_content[i];
		
		//그리고 새롭게 insert 되는 문자열을 넣는다
		for(int j=0; j!= str.string_length; j++)
			string_content[i+j] = str.string_content[j];
		
		//이제 다시 원 문자열의 나머지 뒷부분을 복사한다
		for(; i<string_length; i++)
			string_content[str.string_length + i] = prev_string_content[i];
		
		delete[] prev_string_content;
		
		string_length = string_length + str.string_length;
		return *this;
	}
	
	//만일 초과하지 않는 경우 굳이 동적할당 X
	//효율적으로 insert 하기 위해, 밀리는 부분을 먼저 뒤로 밀어버림
	
	for(int i=string_length - 1; i>=loc; i--)
	{
		//뒤로 밀기. 원래의 문자열 데이터 사라지지 않게 함
		string_content[i + str.string_length] = string_content[i];
	}
	//그리고 insert 되는 문자 다시 집어넣기
	for(int i=0; i<str.string_length; i++)
		string_content[i+loc] = str.string_content[i];
	
	string_length += str.string_length;
	return *this;
}

MyString& MyString::insert(int loc, const char* str)
{
	MyString temp(str);
	return insert(loc, temp);
}

MyString& MyString::insert(int loc, char c)
{
	MyString temp(c);
	return insert(loc, temp);
}

MyString& MyString::erase(int loc, int num)
{
	//loc의 앞부터 시작해서 num 문자를 지운다.
	if(num<0 || loc<0 || loc>string_length)
		return *this;
	
	//erase할 부분이 문자열보다 길다면
	if(loc + num>string_length)
	{
		std::cout<<"Error! Invalid range for erase!"<<'\n';
		return *this;
	}
	
	//지운다는 것은 단순히 뒤의 문자들을 앞으로 끌고 오는 것
	for(int i=loc+num; i<string_length; i++)
		string_content[i-num] = string_content[i];
	
	string_length -= num;
	return *this;
}

int MyString::find(int find_from, MyString& str) const
{
	int i,j;
	if(str.string_length == 0)
		return -1;
	for(i=find_from; i<=string_length - str.string_length; i++)
	{
		for(j=0; j<str.string_length; j++)
		{
			if(string_content[i+j] != str.string_content[j])
				break;
		}
		if(j==str.string_length)
			return i;
	}
	
	return -1; //못 찾는 경우
}

int MyString::find(int find_from, const char* str) const
{
	MyString temp(str);
	return find(find_from, temp);
}

int MyString::find(int find_from, char c) const
{
	MyString temp(c);
	return find(find_from, temp);
}

int MyString::compare(const MyString& str) const
{
	//(*this) - (str)을 수행해서 그 1,0,-1로 그 결과를 리턴
	//1은 (*this) 가 사전식으로 더 뒤에 온다는 의미. 0은 두 문자열이 같다는 의미,
	//-1은 (*this) 가 사전식으로 더 앞에 온다는 의미이다.
	
	for(int i=0; i<std::min(string_length, str.string_length); i++)
	{
		if(string_content[i] > str.string_content[i])
			return 1;
		
		else if(string_content[i] < str.string_content[i])
			return -1;
	}
	
	//여기까지 했는데 끝나지 않았다면 앞 부분까지 모두 똑같은 것이 됨.
	//만일 문자열 길이가 같다면 두 문자열은 아예 같은 문자열
	
	if(string_length == str.string_length)
		return 0;
	
	//참고로 abc와 abcd의 크기 비교는 abcd가 더 뒤에 오게 된다.
	else if(string_length > str.string_length)
		return 1;
	
	return -1;
}

void dosomethingwithString(MyString s)
{
	std::cout<<"Hi"<<"\n";
}

bool MyString::operator==(MyString& str)
{
	return !compare(str);
}

int main(void)
{
	MyString str4("Beautiful World");
	MyString str5("Hello, Beautiful");
	MyString str6("Hello, Beautiful");
	if (str4 == str5)
    	std::cout << "str4 와 str5 같다." << std::endl;
  	else
    	std::cout << "str4 와 str5 는 다르다." << std::endl;

  	if (str5 == str6)
   		std::cout << "str5 와 str6 는 같다." << std::endl;
  	else
    	std::cout << "str5 와 str6 는 다르다" << std::endl;
	return 0;
}