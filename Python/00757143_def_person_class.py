import datetime
import copy
class Person:
    def age(self):
        today=datetime.date.today()
        setday=self.setday
        age=self.agge
        if setday.day-today.day<1 and setday.month-today.month<1 and setday.year-today.year<1:
            print("didn't run")
            return age
        self.setday=today
        age=today.year-self.birthdate.year
        if today<datetime.date(today.year, self.birthdate.month, self.birthdate.day):
            age-=1
        return age
    def __init__(self, name, surname, birthdate, address, telephone, email):
        self.name=name
        self.surname=surname
        self.birthdate=birthdate
        self.address=address
        self.telephone=telephone
        self.email=email
        self.setday=datetime.date(1,1,1)
        today=datetime.date.today()
        age=today.year-self.birthdate.year
        if today<datetime.date(today.year, self.birthdate.month, self.birthdate.day):
            age-=1
        self.agge=age
    @property
    def fullname(self):
        return self.name +" "+ self.surname
    def __del__(self): pass
person=Person("Jane","Doe",datetime.date(1992, 3, 12),"No. 12 Short Street, Greenville","555 456 0987","jane.doe@example.com")
print(person.name)
print(person.email)
print(person.agge)
print(person.age())
print(person.fullname)
"""
輸出:
Jane
jane.doe@example.com
27
didn't run
27
Jane Doe
"""