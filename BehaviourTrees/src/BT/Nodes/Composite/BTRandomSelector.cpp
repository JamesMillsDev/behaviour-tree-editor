#include "BT/Nodes/Composite/BTRandomSelector.h"

#include <iterator>
#include <random>
#include <utility>

using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;

// Gotten from Christopher Smith on StackOverflow: https://stackoverflow.com/a/16421677
template<typename ITER, typename RANDOM_GENERATOR>
static ITER SelectRandomly(ITER start, ITER end, RANDOM_GENERATOR& g)
{
	uniform_int_distribution dis(0, static_cast<int>(std::distance(start, std::move(end))) - 1);
	std::advance(start, dis(g));
	return start;
}

// Gotten from Christopher Smith on StackOverflow: https://stackoverflow.com/a/16421677
template<typename ITER>
static ITER SelectRandomly(ITER start, ITER end)
{
	static random_device rd;
	static mt19937 gen(rd());
	return SelectRandomly(std::move(start), std::move(end), gen);
}

namespace BT
{
	ENodeResult BTRandomSelector::Execute(void* userData)
	{
		if (ENodeResult pendingResult; 
			ExecutePending(userData, pendingResult))
		{
			return pendingResult;
		}

		vector runnable = { m_children };
		while (!runnable.empty())
		{
			auto node = SelectRandomly(runnable.begin(), runnable.end());

			switch ((*node)->Execute(userData))
			{
			case ENodeResult::Failed:
				runnable.erase(node);
				continue;

			case ENodeResult::Succeeded:
				return ENodeResult::Succeeded;

			case ENodeResult::Pending:
				m_pendingChild = *node;
				return ENodeResult::Pending;
			}
		}

		return ENodeResult::Failed;
	}
}
