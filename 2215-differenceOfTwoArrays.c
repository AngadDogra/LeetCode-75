public class Solution {
    public IList<IList<int>> FindDifference(int[] nums1, int[] nums2) {
        IList<int> distinctNums1 = new List<int>();
            IList<int> distinctNums2 = new List<int>();
            foreach (int i in nums1)
            {
                if(Array.IndexOf(nums2, i) == -1 && !distinctNums1.Contains(i))
                {
                    distinctNums1.Add(i);
                }
            }
            foreach (int i in nums2)
            {
                if (Array.IndexOf(nums1, i) == -1 && !distinctNums2.Contains(i))
                {
                    distinctNums2.Add(i);
                }
            }
            IList<IList<int>> result = new List<IList<int>>();
            result.Add(distinctNums1);
            result.Add(distinctNums2);
            return result;
    }
}
