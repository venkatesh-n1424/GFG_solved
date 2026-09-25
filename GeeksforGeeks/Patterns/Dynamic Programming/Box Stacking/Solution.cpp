class Solution {
private:
    struct Box {
        int width;
        int length;
        int height;

        Box(int w, int l, int h) : width(w), length(l), height(h) {}
    };

    void addBox(vector<Box>& boxes, int a, int b, int h) {
        if (a < b) {
            swap(a, b);
        }
        boxes.push_back(Box(a, b, h));
    }

    int solve(int index, const vector<Box>& boxes, vector<int>& memo) {
        if (memo[index] != -1) {
            return memo[index];
        }

        Box current = boxes[index];
        int maxHeight = current.height;

        for (int i = 0; i < boxes.size(); i++) {
            Box next = boxes[i];
            // Strict condition: next box dimensions must be strictly smaller than current box dimensions
            if (next.width < current.width && next.length < current.length) {
                int height = current.height + solve(i, boxes, memo);
                maxHeight = max(maxHeight, height);
            }
        }

        return memo[index] = maxHeight;
    }

public:
    int maxHeight(vector<int>& height, vector<int>& width, vector<int>& length) {
        vector<Box> boxes;
        int n = height.size();

        // Generate all 3 rotations for each box
        for (int i = 0; i < n; i++) {
            addBox(boxes, width[i], length[i], height[i]);
            addBox(boxes, height[i], length[i], width[i]);
            addBox(boxes, height[i], width[i], length[i]);
        }

        int m = boxes.size();
        vector<int> memo(m, -1);
        int ans = 0;

        for (int i = 0; i < m; i++) {
            ans = max(ans, solve(i, boxes, memo));
        }

        return ans;
    }
};