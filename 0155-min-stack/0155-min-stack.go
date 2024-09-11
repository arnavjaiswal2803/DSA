type Node struct {
    val int
    next *Node
}

func NodeConstructor(val int, next *Node) *Node {
    return &Node {
        val: val,
        next: next,
    }
}

type MinStack struct {
    minVal int
    top *Node
}


func Constructor() MinStack {
    return MinStack {
        minVal: math.MaxInt32,
        top: nil,
    }
}


func (this *MinStack) Push(val int)  {
    valToInsert := val
    if  val < this.minVal {
        if this.top != nil {
            valToInsert = 2 * val - this.minVal
        }
        this.minVal = val
    }
    node := NodeConstructor(valToInsert, this.top)
    this.top = node
}


func (this *MinStack) Pop()  {
    if this.top.val < this.minVal {
        this.minVal = 2 * this.minVal - this.top.val
    }
    this.top = this.top.next
    if this.top == nil {
        this.minVal = math.MaxInt32
    }
}


func (this *MinStack) Top() int {
    if this.top.val < this.minVal {
        return this.minVal
    }
    return this.top.val
}


func (this *MinStack) GetMin() int {
    return this.minVal
}


/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(val);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */