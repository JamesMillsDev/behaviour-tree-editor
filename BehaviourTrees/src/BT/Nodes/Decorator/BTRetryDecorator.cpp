#include "BT/Nodes/Decorator/BTRetryDecorator.h"

namespace BT
{
	BTRetryDecorator::BTRetryDecorator(int retryCount)
		: m_retryCount{ retryCount }, m_currentIteration{ 0 }
	{
	}

	ENodeResult BTRetryDecorator::Execute(void* userData)
	{
        if (ENodeResult pendingResult;
            ExecutePending(userData, pendingResult))
        {
            return pendingResult;
        }

        while (m_currentIteration < m_retryCount)
        {
            switch (m_child->Execute(userData))
            {
            case ENodeResult::Failed:
            {
                m_currentIteration++; // Only increment on failure
                break; // Continue to next retry
            }
            case ENodeResult::Succeeded:
            {
                m_currentIteration = 0; // Reset for next time
                return ENodeResult::Succeeded;
            }
            case ENodeResult::Pending:
            {
                m_pendingChild = m_child;
                return ENodeResult::Pending;
            }
            }
        }

        // All retries exhausted
        m_currentIteration = 0;
        return ENodeResult::Failed;
	}
}
