    public boolean isPalindrome(ListNode head) {
        if (head == null) return true;
        int size = 0;
        ListNode temp = head;
        while(temp != null){
            size++;
            temp = temp.next;
        }
        int [] arr = new int[size];
        temp = head ;
        for (int i = 0 ; i < size ; i++){
            arr[i] = temp.val;
            temp = temp.next;
        }
        for (int i = 0 ; i < size/2 ; i++){
            if (arr[i] != arr[size - i - 1]){
                return false;
            }
        }
        return true;
    }
