class Person:
    def __init__(self,name):
        self.name=name
class Publisher(Person):
    def __init__(self,name,title,page,author):
        self.books=Book(title,page,author)
        author.add_books(self.books.title)
        super().__init__(name)
class Author(Person):
    def __init__(self,name):
        self.books=[]
        super().__init__(name)
    def add_books(self,books):
        self.books.append(books)
class Book:
    def __init__(self,title, page,author):
        self.title=title
        self.page=page
        self.author=[author]
    def add_author(self,author):
        self.author.append(author)
#Publisher->Book (compe)
#Author->Book (Aggre)
#Person->Publisher (inhert)
#     L->Author (inhert)