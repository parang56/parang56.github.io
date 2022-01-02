#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char *title; //책의 제목
	char *isbn; //국제표준도서번호
	int price; //책의 정가
public:
	Book(char* mytitle, char* myisbn, int myprice) : price(myprice)
	{
		title = new char[strlen(mytitle)+1];
		strcpy(title,mytitle);
		isbn = new char[strlen(myisbn)+1];
		strcpy(isbn,myisbn);
	}
	Book(const Book& ref) : price(ref.price) //복사 생성자
	{
		title = new char[strlen(ref.title)+1];
		strcpy(title,ref.title);
		isbn = new char[strlen(ref.isbn)+1];
		strcpy(isbn,ref.isbn);
	}
	Book& operator=(const Book& ref) //대입 연산자
	{
		delete []title;
		delete []isbn;
		
		title = new char[strlen(ref.title)+1];
		strcpy(title,ref.title);
		isbn = new char[strlen(ref.isbn)+1];
		strcpy(isbn,ref.isbn);
		price=ref.price;
		return *this;
	}
	void ShowBookInfo()
	{
		cout<<"제목: "<<title<<endl;
		cout<<"ISBN: "<<isbn<<endl;
		cout<<"가격: "<<price<<endl;
	}
	~Book()
	{
		delete []title;
		delete []isbn;
	}
};

class Ebook : public Book
{
private:
	char *DRMKey; //보안관련 키
public:
	Ebook(char* title, char* isbn, int price, char* myDRMKey)
		: Book(title, isbn, price)
	{
		DRMKey = new char[strlen(myDRMKey)+1];
		strcpy(DRMKey,myDRMKey);
	}
	Ebook(const Ebook& ref) //복사 생성자
		: Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey)+1];
		strcpy(DRMKey,ref.DRMKey);		
	}
	Ebook& operator=(const Ebook& ref) //대입 연산자
	{
		Book::operator=(ref); //기초 클래스의 대입 연산자 호출 명령 해야함!
		delete []DRMKey;
		DRMKey=new char[strlen(ref.DRMKey)+1];
		strcpy(DRMKey,ref.DRMKey);
		return *this;
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout<<"인증키: "<<DRMKey<<endl;
	}
	~Ebook()
	{
		delete []DRMKey;
	}
};

int main(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout<<endl;
	Ebook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}