# 用两个栈来实现一个队列，完成队列的Push和Pop操作。
# 队列中的元素为int类型。
# 创建两个栈stack1和stack2，使用两个“先进后出”的栈实现一个“先进先出”的队列。

class Solution:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, node):
        self.stack1.append(node)

    def pop(self):
        if len(self.stack2) == 0:
            while self.stack1:
                self.stack2.append(self.stack1.pop())

        return self.stack2.pop()
