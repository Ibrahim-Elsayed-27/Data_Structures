class Node:
    def __init__(self,value) -> None:
        self.value=value
        self.next=None
        self.prev=None
    def set_next(self,next):
        self.next=next
    def get_next(self):
        return self.next
    def set_prev(self,prev):
        self.prev=prev
    def get_prev(self):
        return self.prev


class DoubleLinked:

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
                    new=Node(value)
                    next.set_next(new)
                    new.set_prev(next)
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
                if self.size!=1:
                    new=Node(self.head.value)
                    temp=self.head.get_next()
                    self.head.value=value
                    self.head.set_next(new)
                    new.set_prev(self.head)
                    new.set_next(temp)
                    temp.set_prev(new)
                else:
                    new=Node(self.head.value)
                    self.head.value=value
                    self.head.set_next(new)
                    new.set_prev(self.head)
            self.print_linked()
            return
        elif index>self.size-1 or index<0:
            print("Error")
            return
        else:
            for i in range(self.size):
                if i!=index:
                    next=next.get_next()
                else:
                    next=next.get_prev()
                    new=Node(value)
                    new.set_next(next.get_next())
                    next.set_next(new)
                    new.set_prev(next)
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
        self.head.set_prev(None)
    
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
                self.head.set_prev(None)
                self.size-=1

        elif index>self.size-1 or index<0:
            print("Error")
            return
        else:
            for i in range(self.size):
                if i!=index:
                    next=next.get_next()
                else:
                    next=next.get_prev()
                    next.set_next(next.get_next().get_next())
                    try:
                        next.get_next().set_prev(next)
                    except:
                        pass
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
                

my_double=DoubleLinked()
text_array=input()
text_array=text_array[1:len(text_array)-1]
linked_array=text_array.split(",")
for i in range(len(linked_array)):
    try:
        my_double.add(int(linked_array[i]))
    except (ValueError):
        del linked_array[i]

operation=input().strip()
if operation=="add":
    value=int(input().strip())
    my_double.add(value)
    my_double.print_linked()
elif operation=="addToIndex":
    index=int(input().strip())
    value=int(input().strip())
    my_double.add_to_index(value,index)
elif operation == "get":
    index=int(input().strip())
    print(my_double.get(index))
elif operation == "set":
    index=int(input().strip())
    value=int(input().strip())
    my_double.set(value,index)
elif operation== "clear":
    my_double.clear()
    my_double.print_linked()
elif operation== "isEmpty":
    print(my_double.is_empty())
elif operation== "size":
    my_double.linked_size()
elif operation== "contains":
    value=int(input().strip())
    my_double.contains(value)
elif operation=="sublist":
    first=int(input().strip())
    last=int(input().strip())
    my_double.sublist(first,last)
elif operation=="remove":
    index=int(input().strip())
    my_double.remove(index)