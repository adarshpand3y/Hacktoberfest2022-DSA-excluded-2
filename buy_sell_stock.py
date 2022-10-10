def max_profit(price,n):
    buy=price[0]
    max_profit=0
    for i in range(1,n):
        if (buy > price[i]):
            buy=price[i]
        elif (price[i]-buy>max_profit):
            max_profit=price[i]-buy;
    return max_profit
if __name__=='__main__':
    price=[7, 1, 5, 6, 4 ];
    n=len(price)
    maxprofit=max_profit(price,n);
    print(maxprofit)
