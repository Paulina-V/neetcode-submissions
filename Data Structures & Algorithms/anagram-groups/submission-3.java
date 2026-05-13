

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        // HashMap: key = sorted word, value = list of anagrams
        HashMap<String, List<String>> map = new HashMap<>();

        for (String str : strs) {
            // Sort the characters of the string
            char[] chars = str.toCharArray();
            Arrays.sort(chars);
            String sorted = new String(chars);

            // If the key doesn't exist, create a new list
            if (!map.containsKey(sorted)) {
                map.put(sorted, new ArrayList<>());
            }

            // Add the original string to the corresponding anagram group
            map.get(sorted).add(str);
        }

        // Return all the grouped anagram lists
        return new ArrayList<>(map.values());
    }
}
