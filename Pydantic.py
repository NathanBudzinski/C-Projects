# Nathan Budzinski
# 4-18-24
# Pydantic, Abstract Classes, and Multiple Inheritance

from typing import Optional
from abc import ABC, abstractmethod
from pydantic import BaseModel, EmailStr
from email_validator import validate_email, EmailNotValidError

class Person(BaseModel):
    first_name: str
    last_name: str
    email: Optional[EmailStr] = None
    phone_number: Optional[str] = None
    age: int

    def get_name(self):
        return self.first_name + self.last_name

    def get_age(self):
        return self.age

    def set_email(self, email):
        try:
            email = validate_email(email, check_deliverability=False)
            self.email = email.normalized
        except EmailNotValidError as e:
            print(str(e))

    def get_email(self):
        return self.email

    def set_phone_number(self, phone_number):
        self.phone_number = phone_number

    def get_phone_number(self):
        return self.phone_number

class Programmer(ABC):
    @abstractmethod
    def get_languages_known(self):
        pass

    @abstractmethod
    def set_languages_known(self):
        pass

class Developer(Person, Programmer):
    languages_known: Optional[list[str]] = None

    def get_languages_known(self):
        return self.languages_known

    def set_languages_known(self, languages_known):
        self.languages_known = languages_known


class Main:
    JohnD = Developer(first_name="John", last_name="Doe", age=21)
    JohnD.set_languages_known(["Assembly", "C++", "C#", "Java", "Python", "SQL", "Visual Basic"])
    JohnD.set_email("johndoe@example.com")
    JohnD.set_phone_number("555-555-555")
    print(JohnD)


Main()
