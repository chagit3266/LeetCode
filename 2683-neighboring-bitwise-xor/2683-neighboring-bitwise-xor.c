bool doesValidArrayExist(int* derived, int derivedSize) {
    int original = 0, pre = 0;
    for(int i= 0; i<derivedSize; i++){
        if(derived[i] == 0){
            pre = pre;
        }else{
            pre = !pre;
        }
    }
    return pre == original;
}