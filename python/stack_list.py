import math
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
    def add_to_index(self,value,index):
        next=self.head
        if index==0:
            if self.size==0:
                self.head=Node(value)
                self.size+=1
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
                y=self.head.value
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
        return y
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
    def __init__(self):
        self.linked= SingleLinked()
    def push(self,value):
        self.linked.add_to_index(value,0)

    def pop(self):
        return self.linked.remove(0)
    
    def peek(self):
        print(self.linked.head.value)
    
    def isEmpty(self):
        print(self.linked.is_empty())
    
    def size(self):
        return self.linked.linked_size()
    def print_stack(self):
        self.linked.print_linked()

my_preced={
    "(":6,
    ")":6,
    "^":2,
    "*":3,
    "/":3,
    "-":5,
    "+":5
}
def preced(operand1,operand2,final,my_stack:Stack):
        #print(operand1,operand2)
        if my_preced[operand1]>=my_preced[operand2]:
            final+=operand2
            my_stack.push(operand1)
        #elif my_preced[operand1]==my_preced[operand2]:
        #    final+=operand2
        #    my_stack.push(operand1)
        else:
            my_stack.push(operand2)
            my_stack.push(operand1)
            
        return final,my_stack

my_stack=Stack()

exp=input().strip()
a=int(input()[2:])
b=int(input()[2:])
c=int(input()[2:])
final=""

operators=["/","*","+","-","**"]
copy_exp=exp
for i in range(len(copy_exp)):
    try:
        if copy_exp[i]=="^":
            copy_exp=copy_exp[:i]+"**"+copy_exp[i+1:]
    except:
        pass

copy_exp_arr=["//" if char=="/" else char for char in copy_exp]
copy_exp=""
for char in copy_exp_arr:
    copy_exp+=char

try:
    print(copy_exp,type(a))
    ans=eval(copy_exp,{"a":a,"b":b,"c":c,})
except:
    print("Error")
    quit()





operators=["+","-","^","/"]
for i in range(len(exp)):
    try:
        if exp[i]=="-" and exp[i+1]=="-":
            if i==0 or not exp[i-1].isalpha():
                exp=exp[:i]+exp[i+2:]
            else:
                exp=exp[:i]+"+"+exp[i+2:]
    except:
        pass
flag=True
for i in range(len(exp)):
    try:
        if exp[i]==exp[i+1] and exp[i] in operators:
            flag=False
            break
    except:
        pass
if flag:
    for char in exp:
        if char.isalpha():
            final+=char
        elif char=="(":
            my_stack.push(char)
        elif char==")":
            check =False
            while(my_stack.size()>0):
                close=my_stack.pop()
                if close=="(":
                    check = True
                    break
                else:
                    final+=close
            if not check:
                print("Error")
                quit()          
        else:
            if my_stack.size()==0:
                my_stack.push(char)
            else:
                operand2=my_stack.pop()
                if char.isdigit() or operand2.isdigit():
                    my_stack.push(operand2)
                    my_stack.push(char)
                else:
                    final,my_stack=preced(char,operand2,final,my_stack) 
    while(my_stack.size()>0):
        final+=my_stack.pop()
    print(final)
    print((round(ans)))
else:
    print("Error")






