class Node:
    def __init__(self,value) -> None:
        self.value=value
        self.next=None
    def set_next(self,next):
        self.next=next
    def get_next(self):
        return self.next


class SingleLinked:

    def __init__(self):
        self.head=None
        self.size=0
    
    def add(self,value):
        if self.size==0:
            self.head=Node(value)
            self.size+=1
        else:
            next=self.head
            while(1):
                if next.get_next()==None:
                    next.set_next(Node(value))
                    self.size+=1
                    break
                else:
                    next=next.get_next()
        
    def add_to_index(self,value,index):
        next=self.head
        if index==0:
            if self.size==0:
                print("Error")
                return
            elif self.size!=0:
                new_value,new_next=self.head.value,self.head.get_next()
                self.head.value=value
                self.head.set_next(new_next)
                self.add_to_index(new_value,1)
            return
        elif index>self.size or index<0:
            print("Error")
            return
        else:
            for i in range(self.size):
                if i!=index-1:
                    next=next.get_next()
                else:
                    new=Node(value)
                    new.set_next(next.get_next())
                    next.set_next(new)
                    self.size+=1    
        self.print_linked()
    def get(self,index):
        next=self.head
        if index>self.size-1 or index<0:
            return "Error"
        else:
            for i in range(self.size):
                if i!=index:
                    next=next.get_next() 
                else:
                    return next.value           

    def set(self,value,index):
        next=self.head
        if index>self.size-1 or index<0:
            print("Error")
            return
        else:
            for i in range(self.size):
                if i!=index:
                    next=next.get_next() 
                else:
                    next.value=value
        self.print_linked()

    def clear(self):
        if self.size==0:
            return
        self.size=0
        self.head.set_next(None)
    
    def is_empty(self):
        return not bool(self.size)


    def remove(self,index):
        next=self.head
        if index==0:
            if self.size==0:
                print("Error")
                return
            elif self.size!=0:
                self.head=self.head.get_next()
                self.size-=1

        elif index>self.size-1 or index<0:
            print("Error")
            return
        else:
            for i in range(self.size):
                if i!=index-1:
                    next=next.get_next()
                else:
                    next.set_next(next.get_next().get_next())
                    self.size-=1
        self.print_linked()
    def sublist(self,first,last):
        if first <0 or first >self.size-1 or last<0 or last > self.size-1 or last<first:
            print("Error")
            return
        else:
            next=self.head
            my_sub_list=[]
            for i in range(self.size):
                if i!=first:
                    next=next.get_next()
                else:
                    my_sub_list.append(next.value)
                    for j in range(i,self.size):
                        next=next.get_next()
                        if j == last:
                            print(my_sub_list)
                            return
                        my_sub_list.append(next.value)

    def contains(self,value):
        next=self.head
        for i in range(self.size):
            if value==next.value:
                print("True")
                return
            else:
                next=next.get_next()
        print("False")

    def linked_size(self):
        print(self.size)

    def print_linked(self):
        my_list=[]
        if self.size==0:
            print([])
            return
        else:
            next=self.head
            value=self.head.value

            while(next.get_next()!=None):
                my_list.append(value)
                next=next.get_next()
                value=next.value
            my_list.append(next.value)
        print(my_list)
                

my_single=SingleLinked()
text_array=input()
text_array=text_array[1:len(text_array)-1]
linked_array=text_array.split(",")
for i in range(len(linked_array)):
    try:
        my_single.add(int(linked_array[i]))
    except (ValueError):
        del linked_array[i]

operation=input().strip()
if operation=="add":
    value=int(input().strip())
    my_single.add(value)
    my_single.print_linked()
elif operation=="addToIndex":
    index=int(input().strip())
    value=int(input().strip())
    my_single.add_to_index(value,index)
elif operation == "get":
    index=int(input().strip())
    print(my_single.get(index))
elif operation == "set":
    index=int(input().strip())
    value=int(input().strip())
    my_single.set(value,index)
elif operation== "clear":
    my_single.clear()
    my_single.print_linked()
elif operation== "isEmpty":
    print(my_single.is_empty())
elif operation== "size":
    my_single.linked_size()
elif operation== "contains":
    value=int(input().strip())
    my_single.contains(value)
elif operation=="sublist":
    first=int(input().strip())
    last=int(input().strip())
    my_single.sublist(first,last)
elif operation=="remove":
    index=int(input().strip())
    my_single.remove(index)