import random

class Process:
    processes={}

    def __init__(self,index,id):
        self.index=index
        self.process_id=id
        self.status=1
        self.processes[index]=id

    def display(self):
        print("Process "+str(self.index)+" ID "+str(self.process_id)+" Status "+str(self.status))

def main():
    n=int(input("Enter number of processes : "))
    ids=random.sample(range(1,100),n)
    print(ids)

    objects=[]
    
    for i in range(n):
        obj=Process(i,ids[i])
        objects.append(obj)
        objects[i].display()

    co_ord = max(Process.processes, key=lambda k: Process.processes[k])
    objects[co_ord].status=0
    print("\nCo-ordinator is Process %d\n" %co_ord)

    for i in range(n):
        objects[i].display()

    elec=int(input("Enter process number who sends ELECTION msg : "))

if __name__=="__main__":
    main()