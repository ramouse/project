#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

// 快速将扑克牌点数映射为数字
inline int get_rank(char c) {
    if (c >= '2' && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    if (c == 'A') return 14;
    return 0;
}

// 评估 5 张牌的函数
array<int, 6> evaluate_hand(const vector<pair<char, char>>& hand) {
    int r[5];
    bool is_flush = true;
    for (int i = 0; i < 5; i++) {
        r[i] = get_rank(hand[i].first);
        if (i > 0 && hand[i].second != hand[i - 1].second) is_flush = false;
    }
    sort(r, r + 5, greater<int>());

    bool is_straight = false, is_A5 = false;
    if (r[0] == r[1] + 1 && r[1] == r[2] + 1 && r[2] == r[3] + 1 && r[3] == r[4] + 1) {
        is_straight = true;
    }
    if (r[0] == 14 && r[1] == 5 && r[2] == 4 && r[3] == 3 && r[4] == 2) {
        is_straight = true;
        is_A5 = true;
    }

    int counts[15] = {0};
    for (int x : r) counts[x]++;
    pair<int, int> freq[5];
    int f_sz = 0;
    for (int i = 14; i >= 2; i--) {
        if (counts[i] > 0) freq[f_sz++] = {counts[i], i};
    }

    sort(freq, freq + f_sz, [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    });

    array<int, 6> res = {0};
    if (is_A5) {
        res[1] = 5; res[2] = 4; res[3] = 3; res[4] = 2; res[5] = 1;
    } else {
        int idx = 1;
        for (int i = 0; i < f_sz; i++) {
            for (int j = 0; j < freq[i].first; j++) {
                res[idx++] = freq[i].second;
            }
        }
    }

    if (is_straight && is_flush && !is_A5 && res[1] == 14) res[0] = 9; // 皇家同花顺
    else if (is_straight && is_flush) res[0] = 8;                      // 同花顺
    else if (freq[0].first == 4) res[0] = 7;                           // 四条
    else if (freq[0].first == 3 && freq[1].first == 2) res[0] = 6;     // 葫芦
    else if (is_flush) res[0] = 5;                                     // 同花
    else if (is_straight) res[0] = 4;                                  // 顺子
    else if (freq[0].first == 3) res[0] = 3;                           // 三条
    else if (freq[0].first == 2 && freq[1].first == 2) res[0] = 2;     // 两对
    else if (freq[0].first == 2) res[0] = 1;                           // 对子
    else res[0] = 0;                                                   // 高牌

    return res;
}

void solve() {
    vector<pair<char, char>> m(4), o(4);
    set<pair<char, char>> used_cards;

    for (int i = 0; i < 4; i++) {
        cin >> m[i].first >> m[i].second;
        used_cards.insert(m[i]);
    }
    for (int i = 0; i < 4; i++) {
        cin >> o[i].first >> o[i].second;
        used_cards.insert(o[i]);
    }

    string ranks_str = "23456789TJQKA";
    string suits_str = "CDHS";
    vector<pair<char, char>> all_deck;
    for (char r : ranks_str) {
        for (char s : suits_str) {
            all_deck.push_back({r, s});
        }
    }

    // 筛选出对两人可选的剩余卡牌
    vector<pair<char, char>> available_cards;
    for (auto& card : all_deck) {
        if (!used_cards.count(card)) {
            available_cards.push_back(card);
        }
    }

    // 核心优化：预计算法国赌神(o)和玩家(m)在选定某张牌时的强度
    // 每一项保存 {卡牌, 该卡牌对应的 eval 结果}
    vector<pair<pair<char, char>, array<int, 6>>> o_choices;
    for (auto& c : available_cards) {
        vector<pair<char, char>> hand = o;
        hand.push_back(c);
        o_choices.push_back({c, evaluate_hand(hand)});
    }

    int global_ans = 1; // 默认玩家（我）必胜

    // 遍历法国赌神选择的暗牌 c
    for (auto& o_choice : o_choices) {
        pair<char, char> c = o_choice.first;
        array<int, 6> v0 = o_choice.second;

        int cur_p1 = -1; // 假定法国赌神选 c 时，玩家无法获胜

        // 玩家（我）从剩余的牌里选 c1（不能和法国赌神的暗牌 c 重合）
        for (auto& m_choice : o_choices) {
            pair<char, char> c1 = m_choice.first;
            if (c1 == c) continue; // 已经被法国赌神挑走了

            // 重新计算玩家配上 c1 后的牌力
            // 因为玩家手牌基础是 m，不能直接用 o_choices 里的 v1，但可以利用预计算的思想
            vector<pair<char, char>> hand_m = m;
            hand_m.push_back(c1);
            array<int, 6> v1 = evaluate_hand(hand_m);

            int match_res = 0;
            if (v1 > v0) match_res = 1;       // 我赢
            else if (v1 < v0) match_res = -1; // 法国赌神赢
            else match_res = 0;               // 平局

            cur_p1 = max(cur_p1, match_res);
        }
        global_ans = min(global_ans, cur_p1);
    }

    if (global_ans == -1) {
        cout << "GeiWoCaPiXie" << endl;
    } else if (global_ans == 1) {
        cout << "WoYaoYanPai" << endl;
    } else {
        cout << "PaiMeiYouWenTi" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}