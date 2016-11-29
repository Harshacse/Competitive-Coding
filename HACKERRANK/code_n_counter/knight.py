def main():
	inp = raw_input()
	rows = inp.split(" ")[0].split("/")
	check = inp.split(" ")[1]
	board = []
	white = ['R','N','B','Q','K','P']
	black = ['r','n','b','q','k','p']
	if check == 'w':
		check = 1
	else:
		check = 0
	x = []
	y = []
	for each in rows:
		count = 0
		j = 0
		temp = []
		while count<len(each):
			if each[count] in white or each[count] in black:
				if each[count] == 'N' and check == 1:
					x.append(j)
					y.append(len(board))
				if each[count] == 'n' and check == 0:
					x.append(j)
					y.append(len(board))
				temp.append(each[count])
				j+=1
			else:
				temp.extend([0]*int(each[count]))
				j+=int(each[count])
			count += 1
		board.append(temp)

	if check == 1:
		people = white
	else:
		people = black
	pos = ['a','b','c','d','e','f','g','h']
	result = [[],[]]
	for i in range(len(x)):
		if x[i]-1>=0:
			if y[i]-2>=0:
				if board[y[i]-2][x[i]-1] not in people:
					result[i].append(pos[x[i]]+str(8-y[i])+pos[x[i]-1]+str(10-y[i]))

		if x[i]+1<8:
			if y[i]-2>=0:
				if board[y[i]-2][x[i]+1] not in people:
					result[i].append(pos[x[i]]+str(8-y[i])+pos[x[i]+1]+str(10-y[i]))

		if x[i]-2>=0:
			if y[i]-1>=0:
				if board[y[i]-1][x[i]-2] not in people:
					result[i].append(pos[x[i]]+str(8-y[i])+pos[x[i]-2]+str(9-y[i]))

		
		if x[i]+2<8:
			if y[i]-1>=0:
				if board[y[i]-1][x[i]+2] not in people:
					result[i].append(pos[x[i]]+str(8-y[i])+pos[x[i]+2]+str(9-y[i]))

		if x[i]-2>=0:
			if y[i]+1<8:
				if board[y[i]+1][x[i]-2] not in people:
					result[i].append(pos[x[i]]+str(8-y[i])+pos[x[i]-2]+str(7-y[i]))
		
		if x[i]+2<8:
			if y[i]+1<8:
				if board[y[i]+1][x[i]+2] not in people:
					result[i].append(pos[x[i]]+str(8-y[i])+pos[x[i]+2]+str(7-y[i]))

		if x[i]-1>=0:
			if y[i]+2<8:
				if board[y[i]+2][x[i]-1] not in people:
					result[i].append(pos[x[i]]+str(8-y[i])+pos[x[i]-1]+str(6-y[i]))
		
		if x[i]+1<8:
			if y[i]+2<8:
				if board[y[i]+2][x[i]+1] not in people:
					result[i].append(pos[x[i]]+str(8-y[i])+pos[x[i]+1]+str(6-y[i]))

	
	print_list = result[0]
	print_list.extend(result[1])
	string_print = "["
	for each in range(0,len(print_list)-1):
		string_print += print_list[each]+","
	
	if len(print_list)>0:
		string_print += print_list[-1]
	string_print += "]"
	print string_print
	return

main()