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
	void ShowBookInfo()
	{
		cout<<"제목: "<<title<<endl;
		cout<<"ISBN: "<<isbn<<endl;
		cout<<"가격: "<<price<<endl;
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
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout<<"인증키: "<<DRMKey<<endl;
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