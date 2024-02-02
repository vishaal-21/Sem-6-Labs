class Subsets:
    def generate_subsets(self,nums):
        subsets=[]
        total_subsets=2**len(nums)

        for i in range(total_subsets):
            binary=str(bin(i)[2:])
            binary='0'*(len(nums)-len(binary))+binary

            res=[]
            for j in range(len(nums)):
                ch=binary[j]
                if(ch=='1'):
                    res.append(nums[j])

            subsets.append(res)

        subsets.sort()
        return subsets


nums=[4,5,6]
object=Subsets()
subsets=object.generate_subsets(nums)

print(subsets)