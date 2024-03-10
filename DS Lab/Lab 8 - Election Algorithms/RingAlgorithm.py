import random

class Ring:
    processes={}

    def __init__(self,index,id,ids):
        self.index=index
        self.process_id=id
        self.processes[index]=id
        self.process_ids=ids
        self.coord_id=self.process_ids.index(max(self.process_ids))
        self.coord=max(self.process_ids)

    def display(self):
        print(f"Process {self.index} ID {self.process_id} Coordinator : Process {self.coord_id} => {self.coord}")
        
    def startElection(self,elec):        
        if 0 <= elec < len(self.process_ids) and elec != self.coord_id:
            self.process_ids.remove(self.coord)
            print(self.process_ids)
        else:
            print("Invalid process number for election")
            
        if self.process_ids:
            self.coord=max(self.process_ids)
            self.coord_id=self.process_ids.index(self.coord)
            return self.coord,self.coord_id
        

def main():
    n=int(input("Enter number of processes : "))
    ids=random.sample(range(1,100),n)

    objects=[]
    new_co=new_co_id=0
    
    for i in range(n):
        obj=Ring(i,ids[i],ids)
        objects.append(obj)
        objects[i].display()
        
    elec=int(input(f"\nEnter process number who sends ELECTION msg (0 to {n-1} except {objects[0].coord_id}) : "))
    
    for i in range(n):
        if objects[i].index==elec:
            new_co,new_co_id=objects[i].startElection(elec)
         
    for i in range(n):
        objects[i].coord=new_co
        objects[i].coord_id=new_co_id   
        objects[i].display()
        

if __name__=="__main__":
    main()