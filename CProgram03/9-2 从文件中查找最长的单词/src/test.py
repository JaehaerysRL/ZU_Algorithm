# -*- coding: utf-8 -*-
#!/usr/bin/env python3
# 9-2 从文件中查找最长的单词（20分，请勿修改） (20分)
#data.txt中保存有若干个单词，每个单词一行。请编写一个程序从文件中将所有单词读出，找到其中最长的单词，然后将其保存到result.txt中，程序须保存test.py中。注意：题目不要求去重，重复出现的单词算不同的单词。

#输入格式：
#请查看data.txt
#输出格式： 用以下格式输出最长的字符串到result.txt中:
#The longest word is: zhang 
#如果有多个单词，则每个单词用英文逗号间隔(结尾无逗号)：
#The longest words are: zhang,xiang

words = []
with open('data.txt','r') as f1:
    for line in f1.readlines():
        if line != None:
            tmp = line.strip()
            tmp = ''.join(tmp)
            words.append(tmp)
f1.close

maxLen = 0
for word in words:
    tmpLen = len(word)
    if tmpLen > maxLen:
        maxLen = tmpLen
maxList = []
for word in words:
    tmpLen = len(word)
    if tmpLen == maxLen:
        maxList.append(word)

with open('result.txt','w') as f2:
    if(len(maxList)==1):
        f2.write('The longest word is: '+maxList[0])
    else:
        f2.write('The longest words are: '+maxList[0])
        for i in range(len(maxList)-1):
            f2.write(','+maxList[i+1])
f2.close