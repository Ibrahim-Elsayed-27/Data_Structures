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
        #self.print_linked()
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
        return self.size

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
                
class Stack:
    
    def __init__(self,stack_array):
        self.linked= SingleLinked()
        for i in range(len(stack_array)):
            try:
                self.linked.add(int(stack_array[i]))

            except (ValueError):
                    del stack_array[i]    
    def push(self,value):
        if  my_stack.size()==0:
            self.linked.add(value)
        else:
            self.linked.add_to_index(value,0)

    def pop(self):
        self.linked.remove(0)
    
    def peek(self):
        print(self.linked.head.value)
    
    def isEmpty(self):
        print(self.linked.is_empty())
    
    def size(self):
        return self.linked.linked_size()
    def print_stack(self):
        self.linked.print_linked()


text_array=input()
text_array=text_array[1:len(text_array)-1]
stack_array=text_array.split(",")
my_stack=Stack(stack_array)


operation=input().strip()

if operation=="push":
    #print(my_stack.size())
    value=int(input().strip())
    my_stack.push(value)
    my_stack.print_stack()
elif operation=="pop":
    if my_stack.size()==0:
        print("Error")
    else:  
        my_stack.pop()
        my_stack.print_stack()
elif operation=="peek":
    if my_stack.size()==0:
        print("Error")
    else:    
        my_stack.peek()
elif operation=="isEmpty":
    my_stack.isEmpty()
elif operation=="size":
    print(my_stack.size())
else:
    print("Error")