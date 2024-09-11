var Node = function(val, next) {
    this.val = val;
    this.next = next;
}

var MinStack = function() {
    this.minVal = Number.MAX_SAFE_INTEGER;
    this.topmost = null;
};

/** 
 * @param {number} val
 * @return {void}
 */
MinStack.prototype.push = function(val) {
    let valToInsert = val;
    if (val < this.minVal) {
        if (this.topmost !== null) {
            valToInsert = 2 * val - this.minVal;
        }
        this.minVal = val;
    }
    const node = new Node(valToInsert, this.topmost);
    this.topmost = node;
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    if (this.topmost.val < this.minVal) {
        this.minVal = 2 * this.minVal - this.topmost.val;
    }
    this.topmost = this.topmost.next;
    if (this.topmost === null) {
        this.minVal = Number.MAX_SAFE_INTEGER;
    }
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.topmost.val < this.minVal ? this.minVal : this.topmost.val;
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
   return this.minVal; 
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(val)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */