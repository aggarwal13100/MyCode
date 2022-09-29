class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if total gas < total cost then solution can't exists
        // if total gas > total cost then a solution definitely exist
        // and it is given that solution is unique
        // why? sol exits
        
        // suppose M->X->M is journey
        // Given :
        // Total gas - Total cost > 0   -----(1)
        
        // Total gas = gas(M to X) + gas(X to M)
        // Total cost = cost(M to X) + cost(X to M)
        
        // gas(M to X)-cost(M to X) = -a <0  -----(2)
        // gas(X to M)-cost(X to M) > a it should be since (1)
        // So, we can start from X instead of M
        // when we reach M we have gas >a so solution is possible
        //similarly, if we encounter in between T s.t X->T->M
        // there is no remaining gas at T then we start from T
        
        int totalStation = gas.size();
        int totalGas = 0;
        int totalCost = 0;
        for(int i=0;i<totalStation;i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
        }
        
        if(totalGas<totalCost){
            return -1;
        }
        
        //now one unique solution exits
        int availableGas = 0;
        int startedStation = 0;
        for(int i=0;i<totalStation;i++){
            availableGas +=gas[i]-cost[i];
            
            if(availableGas<0){
                availableGas = 0;
                startedStation = i+1;
            }
        }
        
        return startedStation;
    }
};
