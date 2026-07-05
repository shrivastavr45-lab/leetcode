class Solution {
    public int change(int amount, int[] coins) {

        int n = coins.length;

        int[][] dp = new int[n + 1][amount + 1];

        dp[n][0] = 1;

        for (int i = n - 1; i >= 0; i--) {

            dp[i][0] = 1;

            for (int amt = 1; amt <= amount; amt++) {

                int pick = 0;

                if (amt >= coins[i])
                    pick = dp[i][amt - coins[i]];

                int notPick = dp[i + 1][amt];

                dp[i][amt] = pick + notPick;
            }
        }

        return dp[0][amount];
    }
}