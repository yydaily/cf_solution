import random
import os
import webbrowser
import string
import sys

m = {}

def print_usage():
	print('''USAGE
python question.py get 1800 2400	: get a problem which score is in [1800,2400]
python question.py get low/mid/high	: get a problem where score is in [0,1700]/[1800,2400]/[2500,inf)
python question.py add 1 A			: remark the problem 1/A has been solved''')

def solve(question):
	params = question.split('/')
	print(params[0] + ' ' + params[1])
	url = "https://codeforces.com/problemset/problem/" + question
	webbrowser.open(url)
	command = './generate.sh ' + params[0] + ' ' + params[1]
	os.popen(command)

def handler(l, r):
	question = []
	with open('out', 'r') as f:
		while True:
			x = f.readline()
			if not x:
				break
			y = x.split(' ')
			if len(y) < 3:
				continue
			try:
				nouse = int(y[2])
			except ValueError:
				continue
			if l <= int(y[2]) and int(y[2]) <= r:
				question.append(y[0] + '/' + y[1])
	if len(question) <= 0:
		print("invalid question len")
		return
	x = int(random.random() * len(question))
	solve(question[x])

if __name__ == '__main__':
	if len(sys.argv) == 1:
		print_usage()
		exit(0)	
	if sys.argv[1] == 'add':
		if len(sys.argv) != 4:
			print("invalid params")
			print_usage()
			exit(0)
		with open('./in', 'a+') as f:
			f.write(sys.argv[2] + ' ' + sys.argv[3] +'\n')
	elif sys.argv[1] == 'get':
		if len(sys.argv) != 3 and len(sys.argv) != 4:
			print("invalid params len")
			print_usage()
			exit(0)
		l = int(0)
		r = int(4000)
		if len(sys.argv) == 3:
			if sys.argv[2] != 'low' and sys.argv[2] != 'mid' and sys.argv[2] != 'high':
				print("invalid params")
				print_usage()
				exit(0)
			if sys.argv[2] == 'low':
				l = 0
				r = 1700
			elif sys.argv[2] == 'mid':
				l = 1800
				r = 2400
			else:
				l = 2500
				r = 4000
		else:
			l = int(sys.argv[2])
			r = int(sys.argv[3])
		handler(l, r)
	else:
		print("invalid func_name")
		print_usage()


