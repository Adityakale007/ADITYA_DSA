class MovieRentingSystem {
private:
    unordered_map<int, set<pair<int,int>>> unrented; // movie -> set of (price, shop)
    set<tuple<int,int,int>> rented; // set of (price, shop, movie)
    unordered_map<int, unordered_map<int,int>> price; // price[shop][movie]

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], p = e[2];
            price[shop][movie] = p;
            unrented[movie].insert({p, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        if (unrented.count(movie)) {
            for (auto it = unrented[movie].begin(); it != unrented[movie].end() && res.size() < 5; ++it)
                res.push_back(it->second);
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int p = price[shop][movie];
        unrented[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int p = price[shop][movie];
        rented.erase({p, shop, movie});
        unrented[movie].insert({p, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto it = rented.begin(); it != rented.end() && cnt < 5; ++it, ++cnt) {
            res.push_back({get<1>(*it), get<2>(*it)});
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */
