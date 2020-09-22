import random
import webbrowser
import string

def get():
	index = random.randint(1, 1419)
	index2 = random.randint(0, 5) # A B C D E F
	index2 = str(index2)
	trans = string.maketrans('012345','ABCDEF')
	index2 = index2.translate(trans)
	return str(index), index2

def get_filter():
	m = {}
	with open('in', 'r') as f:
		while True:
			a = f.readline()
			if not a:
				break
			a = str(a)
			m[a] = True
	while True:
		x, y = get()
		key = x + ' ' + y + '\n'
		if key in m:
			continue
		return x, y

if __name__ == '__main__':
	index, index2 = get_filter()
	last = "https://codeforces.com/problemset/problem/" + str(index) + "/" + str(index2)
	webbrowser.open(last)

