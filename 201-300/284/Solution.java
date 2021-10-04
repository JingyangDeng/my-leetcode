// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

//可以将设置一个变量next来保存迭代器当前首部的变量
class PeekingIterator implements Iterator<Integer> {
    Iterator<Integer> iterator;
    int next = 0;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
        this.iterator = iterator;
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if(next == 0) next = iterator.next();
        return next;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
        if(next > 0) {
            int ret = next;
            next = 0;
            return ret;
        }
	    return iterator.next();
	}
	
	@Override
	public boolean hasNext() {
	    return next > 0 || iterator.hasNext();
	}
}
