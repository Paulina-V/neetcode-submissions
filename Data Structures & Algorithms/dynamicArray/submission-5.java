class DynamicArray {
    private int[] array;
    private int length;
    private int capacity;

    public DynamicArray(int capacity) {
        this.capacity = capacity;
        this.length = 0;
        this.array = new int[this.capacity];
    }

    public int get(int i) {
        return array[i];
    }

    public void set(int i, int n) {
        array[i] = n;
    }

    public void pushback(int n) {
        if (length == capacity){
            resize();
        }
        array[length] = n;
        length++;
    }

    public int popback() {
        int ret = array[length-1];
        array[length-1] = 0;
        length--;
        
        return ret;
    }

    private void resize() {
        capacity *= 2;
        int[] array2 = new int[capacity];
        for(int i = 0; i < length; i++){
            array2[i] = array[i];
        }
        array = array2; 
    }

    public int getSize() {
        return length;
    }

    public int getCapacity() {
        return capacity;
    }
}
