#include <bits/stdc++.h>
using namespace std;

#define sci(x) static_cast<int>((x))

// Does IO
void solve() {
    int nCommas{}, nPeriods{}, nWords{};
    vector<string> nouns, trans, intrans, conjs;
    cin >> nWords >> nCommas >> nPeriods;
    for (int i{}; i < nWords; ++i) {
        string tok, type;
        cin >> tok >> type;
        if (type[0] == 'n') nouns.push_back(move(tok));
        else if (type[0] == 't') trans.push_back(move(tok));
        else if (type[0] == 'i') intrans.push_back(move(tok));
        else conjs.push_back(move(tok));
    }

    const int maxVerbs = nPeriods + min(nPeriods, sci(conjs.size()));
    int bestTV{};
    int bestITV{};
    int maxWords{};
    for (int tv{}; tv <= sci(trans.size()); ++tv) {
        for (int itv{}; itv <= sci(intrans.size()); ++itv) {
            const int nounsLeft = sci(nouns.size()) - tv * 2 - itv; // 2 nouns required per tv, 1 per itv
            if (nounsLeft < 0 || tv + itv > maxVerbs) break;

            const int extraNouns = tv > 0 ? min(nCommas, nounsLeft) : 0;
            const int conjsUsed =
                min(sci(conjs.size()), (tv + itv) / 2); // (tv + itv) / 2 refers to the max possible conjunctions usable
            // given how many sentence pieces we have

            const int total = tv * 3 + itv * 2 + extraNouns + conjsUsed;
            if (total > maxWords) {
                maxWords = total;
                bestTV = tv;
                bestITV = itv;
            }
        }
    }

    int curNoun{};
    vector<string> phrases; // individual sentence pieces (1 of two forms, with itv or tv)
    for (int i{}; i < bestTV; ++i) {
        string noun1{nouns[curNoun++]};
        string noun2{nouns[curNoun++]};
        phrases.push_back(move(noun1) + " " + trans[i] + " " + move(noun2));
    }
    for (int i{}; i < bestITV; ++i) {
        string noun1{nouns[curNoun++]};
        phrases.push_back(move(noun1) + " " + intrans[i]);
    }
    // Now we can tack on all the extra nouns
    // So long as we have commas and nouns to choose
    if (bestTV > 0) {
        auto& s = phrases.front();
        for (int iC{}; iC < nCommas && curNoun < sci(nouns.size()); ++iC) { s.append(", " + nouns[curNoun++]); }
    }

    vector<string> sentences;
    // I think what you’d do here is build the longest sentence possible, using every conjunction, then add phrases so
    // long as you have periods
    int curPhrase{};
    for (string conj : conjs) {
        if (curPhrase + 1 >= phrases.size()) break;
        string p1{phrases[curPhrase++]};
        string p2{phrases[curPhrase++]};
        sentences.push_back(move(p1) + " " + move(conj) + " " + move(p2));
    }
    sentences.insert(sentences.end(), phrases.begin() + curPhrase,
                     phrases.end()); // add all the remaining phrases as without conjunction

    string result;
    for (const auto& s : sentences) { result += s + ". "; }
    if (!result.empty()) result.pop_back();
    cout << maxWords << '\n' << result << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef FILE
    freopen("filename.in", "r", stdin);
    freopen("filename.out", "w", stdout);
#endif
    int numTests{};
    cin >> numTests;
    for (int i{}; i < numTests; ++i) { solve(); }
}
