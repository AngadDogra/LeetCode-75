class RecentCounter {

    private Queue<Integer> q;
    public RecentCounter() {
        q = new LinkedList<>();
    }
    
    public int ping(int t) {
        // t is time in milliseconds
        // add to queue if within range of t-3000, t
        q.add(t);
        while (!q.isEmpty() && q.peek() < t-3000){
            q.poll();
        }
        return q.size();
    }
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter obj = new RecentCounter();
 * int param_1 = obj.ping(t);
 */
