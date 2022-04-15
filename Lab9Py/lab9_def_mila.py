# -*- coding: utf-8 -*-
import string

def FindLength(string, n):
    splited_string = string.split()
    sorted_splited = ClearOfThePunctuation(splited_string)
    less_length_array = []
    for i in range(len(sorted_splited)):
        if len(sorted_splited[i]) < n:
            less_length_array.append(sorted_splited[i])
    for j in range(len(less_length_array)):
        sorted_splited.remove(less_length_array[j])
    return sorted_splited

def ClearOfThePunctuation(row):
    new_row = []
    for i in range(len(row)):
        new_row.append(row[i].strip(string.punctuation))
    return new_row