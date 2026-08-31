#include "PmergeMe.hpp"

#include <algorithm>

bool PmergeMe::buildPairsDeq(std::vector<Pairs> &pairs, std::deque<int> const &data, bool &hasStraggler, int &straggler) const
{
    if (data.size() < 2)
        return true;

    hasStraggler = (data.size() % 2 == 1);
    for (size_t i = 0; i + 1 < data.size(); i += 2)
    {
        int a = data[i];
        int b = data[i + 1];
        if (a < b)
            std::swap(a, b);
        Pairs pair;
        pair.winner = a;
        pair.loser = b;
        pairs.push_back(pair);
    }
    if (hasStraggler)
        straggler = data.back();
    return true;
}

void PmergeMe::insertLosersDeq(std::deque<int> &mainChain, std::deque<int> const &losers, bool hasStraggler, int straggler)
{
    if (!losers.empty())
    {
        int first = losers[0];
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), first), first);
    }

    std::vector<size_t> jacobsthalSequence = Jacobsthal(losers.size());
    for (size_t k = 0; k < jacobsthalSequence.size(); ++k)
    {
        size_t j = jacobsthalSequence[k];
        if (j < 2 || j > losers.size())
            continue;
        int value = losers[j - 1];
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), value), value);
    }

    if (hasStraggler)
        mainChain.insert(std::lower_bound(mainChain.begin(), mainChain.end(), straggler), straggler);
}

std::deque<int> PmergeMe::sortingDeque(std::deque<int> data)
{
    if (data.size() <= 1)
        return data;

    bool hasStraggler = false;
    int straggler = 0;

    std::vector<Pairs> pairs;
    std::deque<int> winnerSorted;

    if (!buildPairsDeq(pairs, data, hasStraggler, straggler))
        return data;

    std::vector<int> winners;
    std::deque<int> winnersTmp;

    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].winner);

    for (size_t i = 0; i < pairs.size(); ++i)
        winnersTmp.push_back(pairs[i].winner);

    winnerSorted = sortingDeque(winnersTmp);

    std::vector<bool> used(winners.size(), false);

    std::deque<int> reorderLoser;
    for (size_t i = 0; i < winnerSorted.size(); ++i)
        reorderLoser.push_back(0);

    for (size_t i = 0; i < winnerSorted.size(); i++)
    {
        for (size_t j = 0; j < winners.size(); j++)
        {
            if (winners[j] == winnerSorted[i] && !used[j])
            {
                reorderLoser[i] = pairs[j].loser;
                used[j] = true;
                break;
            }
        }
    }
    data.clear();
    data = winnerSorted;
    insertLosersDeq(data, reorderLoser, hasStraggler, straggler);

    return data;
}