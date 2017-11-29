struct oper{
        int l, r, k;
    };

    oper operarray[M];      //array of operations
    int MIN[N];             //MIN[i] stores minimum cost for removing A[i]
    vector<int> L[N], R[N];
    //arrays as defined in above paragraph
    //except now they store indices of operations instead of their cost

    set < pair < int, int > > iset;
    //first element of pair stores value of operation cost
    //second stores the index of operation

    for i = 1 to M:
        left = operarray[i].l
        right = operarray[i].r

        L[left].push_back(i)
        R[right].push_back(i)

    for i = 1 to N:

        //add all operations beginning at i
        for j = 0 to L[i].size() - 1:
            operindex = L[i][j]     //index of operation beginning here
            cost  = operarray[operindex].k

            //insert in set
            iset.insert(make_pair(cost, operindex))

        MIN[i] = iset.begin()->first;   //first element of the set

        //remove all operations ending at i
        for j = 0 to R[i].size() - 1:
            operindex = R[i][j]     //index of operation beginning here
            cost  = operarray[operindex].k

            //erase from set
            iset.erase(make_pair(cost, operindex))




/*Prob:M queries given :assign a cost ci for all i between li and ri(both inclusive) ,1<=li<=ri<=N.Find min ci for all i.
N log M complexity.*/
