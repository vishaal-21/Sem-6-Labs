class Target:
    def find_pair(self,nums,target):
        dict={}
        list=[]

        for i in range(len(nums)):
            diff=target-nums[i]

            if diff in dict:
                list.append([dict[diff],i])
            dict[nums[i]]=i
        print(dict)
        print(list)



nums=[10,20,10,40,50,60,70]
target=30
obj=Target()
obj.find_pair(nums,target)
