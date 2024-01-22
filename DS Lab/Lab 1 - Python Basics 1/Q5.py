list=[1,4,2,6,4,7]
print("list",list)
print("list[1:4]",list[1:4])
print("list*2",list*2)

list.append(21)
print("appending 21",list)

list.pop()
print("popping",list)

list.remove(6)
print("removing 6",list)

list.insert(0,100)
print("inserting 100 on index 0",list)

list.reverse()
print("reversed list",list)