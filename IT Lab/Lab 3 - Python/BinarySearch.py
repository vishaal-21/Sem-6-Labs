def bin_srch(nums,low,high,key):
    if low<=high:
        mid=low+(high-low)//2

        if nums[mid]==key:
            return mid
        elif nums[mid]>key:
            return bin_srch(nums,low,mid-1,key)
        elif nums[mid]<key:
            return bin_srch(nums,mid+1,high,key)
    else:
        return -1
    

def main():
    nums=[]
    
    print("Enter 6 numbers : ")
    for i in range(0,6):
        x=int(input())
        nums.append(x)

    nums.sort()
    print(nums)

    key=int(input("Enter element to be searched : "))
    low=0
    high=len(nums)-1
    pos=bin_srch(nums,low,high,key)

    if pos==-1:
        print("Element not found")
    else:
        print("Element at index",pos)

if __name__=='__main__':
    main()