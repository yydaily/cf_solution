from bs4 import BeautifulSoup

import sys
import urllib
import urllib2

def show_split() :
	print("=================================================================================")

def find(a, key, ind = 0): #{{{
	if not a:
		return None
	result = a.find_all(key)
	if not result:
		return None
	if len(result) <= ind:
		return None
	return result[ind] #}}}

def raw_print(a):
	if a.isspace():
		return
	if a.isupper():
		sys.stdout.write(' ')
	sys.stdout.write(a)

def print_problem_name(tr): 
	problem_dict = find(find(tr, "td"), "a")
	if not problem_dict:
		return
	problem_name = problem_dict.string
	for c in problem_name:
		raw_print(c)

def print_problem_score(tr):
	span = find(find(tr, "td", 3), "span")
	sys.stdout.write(' ')
	if not span:
		return
	for c in span.string:
		raw_print(c)

def get_one(ind) :
	url = "https://codeforces.com/problemset/page/" + str(ind)
	req = urllib2.Request(url)
	res_data = urllib2.urlopen(req)
	res = res_data.read()
	soup = BeautifulSoup(res, 'html.parser')
	all_tr = soup.find_all('tr')
	for tr in all_tr:
		print_problem_name(tr)
		print_problem_score(tr)
		print ""

if __name__ == '__main__':
	for i in range(1, 68):
		get_one(i)
#soup = BeautifulSoup(html_doc, 'html.parser')

