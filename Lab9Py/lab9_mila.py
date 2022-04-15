# -*- coding: utf-8 -*-
from lab9_def_mila import *

string = """Later, it was said the man came from the north,
from Ropers Gate He came on foot leading his laden horse by the bridle 
It was late afternoon and the ropers’, saddlers’ and tanners’ stalls were already closed, the street empty. 
It was hot but the man had a black coat thrown over his shoulders. He drew attention to himself
"""
n = int(input("Введите длину слова:"))
sorted_string = FindLength(string, n)
print(sorted_string)