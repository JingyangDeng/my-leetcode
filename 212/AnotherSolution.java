//此解法适用于words长度很大，而board较小的情况
//建立Trie树对单词进行预处理，在board上dfs并根据树来剪枝
//此题细节较多，更多优化见注释
class TrieNode {
    public String value = "";
    public HashMap<Character, TrieNode> children = new HashMap<>();
    public void insert(String word){
        char key;
        TrieNode curNode = this;
        for(int i = 0; i < word.length(); i++){
            key = word.charAt(i);
            if(!curNode.children.containsKey(key)){
                TrieNode newNode = new TrieNode();
                curNode.children.put(key, newNode);
            }
            curNode = curNode.children.get(key);
        }
        curNode.value = word;
    }
}

class Solution {
    private int m, n;
    //private int[][] visited;
    private int[][] dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    private TrieNode root;
    private List<String> ret = new ArrayList<String>();

    public List<String> findWords(char[][] board, String[] words) {
        m = board.length;
        n = board[0].length;
        //visited = new int[m][n];
        root = buildTree(words);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(board, root, i, j);
            }
        }
        return ret;
    }

    private TrieNode buildTree(String[] words){
        TrieNode root = new TrieNode();
        for(String word : words){
            root.insert(word);
        }
        return root;
    }

    private void dfs(char[][] board, TrieNode root, int i, int j){
        char key = board[i][j];
        if(!root.children.containsKey(key)) return;
        
        //临时替换board上经过的符号，此操作可免去使用visited
        //visited[i][j] = 1;
        char ch = board[i][j];
        board[i][j] = '#';

        TrieNode node = root.children.get(key);
        if(node.value.length() > 0) {
            ret.add(node.value);
            //把已经加入节点的word删除，避免重复操作
            node.value = "";
        }

        for(int[] d : dir){
            int di = d[0], dj = d[1];
            int ni = i + di, nj = j + dj;
            if(isValid(ni, nj)){
                dfs(board, node, ni, nj);
            }
        }
        
        //对于已经搜索到底的路径可以递归地删除，避免重复搜索！！！
        if (node.children.isEmpty()) {
           root.children.remove(ch);
        }

        //visited[i][j] = 0;
        board[i][j] = ch;
    }

    private boolean isValid(int i, int j){
        return i >= 0 && j >= 0 && i < m && j < n;
    }
}
