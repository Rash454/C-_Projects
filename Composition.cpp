#include<iostream.h>
class Book{
char * title;
int isbn;
public:
Book(char *title , int isbn){
	this->title= new char [strlen(title)+1];
	strcpy(this->title,title);
	this->isbn=isbn;
	cout<<"inside const of Book class\n";
	
}
void setTitle(char *t);

void setIsbn(int i){
isbn=i;
}
/*Book (){
	cout<<"inside default const of Book class\n";	
}*/
char * getTitle (){
	return title;
}
int getIsbn(){
	return isbn;
}
~Book(){
	delete [] title ;
}
};

void Book::setTitle(char *t){
delete []title;
title=new char [strlen(t)+1];
strcpy(title,t);
}
class Library{
int branch;
char lname[20];
 int n;
 Book **Books;
public:	
Library (char ln[] ,int br ,int n){
	cout<<"inside const of Library class\n";	
   strcpy(lname, ln);
   branch=br;
   this->n=n;
   Books=new Book *[n];
   char *bn ;
   int isbn;
   for ( int i=0 ; i<n ; i++){   // for loop to fill the array
   	cout<<"Please enter Book Title and ISBN: ";
   	cin>>bn>>isbn;
   	Books[i]=new Book(bn , isbn);
   }
}
/*Book getBook(){
	return b;
}*/
void printAllBooks(){        // for loop to print all members in the array
for ( int i=0 ; i<n ; i++)
cout<<Books[i]->getTitle()<<"\t"<< Books[i]->getIsbn()<<endl;	
}
Book *searchForABook(char *t){   // for loop to find one book matches to the title I entered 
for ( int i=0 ; i<n ; i++)
if(strcmp(Books[i]->getTitle(),t)==0)
return Books[i];	
}
Book **SearchForBooks(char * title){
int c=0;	
for ( int i=0 ; i<n ; i++)
if(strcmp(Books[i]->getTitle(),title)==0)
c++;

Book **newBooks = new Book *[c];
int j=0;
for ( int i=0 ; i<n ; i++)
if(strcmp(Books[i]->getTitle(),title)==0)
newBooks[j++]=new Book(Books[i]->getTitle(),Books[i]->getIsbn())	;
return newBooks;


}
};

main(){
	Library l1("AAUP",45 ,3);
	l1.printAllBooks();
	cout<<l1.searchForABook("C++")<<endl;
    cout<<l1.SearchForBooks("C++");
}

