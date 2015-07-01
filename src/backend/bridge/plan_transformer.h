/**
 * @brief Header for postgres plan transformer.
 *
 * Copyright(c) 2015, CMU
 */

#pragma once

extern "C" {
#include "executor/execdesc.h"
}

#include "backend/planner/abstract_plan_node.h"

namespace peloton {
namespace bridge {

//===--------------------------------------------------------------------===//
// Plan Transformer (From Postgres To Peloton)
//===--------------------------------------------------------------------===//

class PlanTransformer {

 public:
  PlanTransformer(const PlanTransformer &) = delete;
  PlanTransformer& operator=(const PlanTransformer &) = delete;
  PlanTransformer(PlanTransformer &&) = delete;
  PlanTransformer& operator=(PlanTransformer &&) = delete;

  PlanTransformer(){};

  static PlanTransformer& GetInstance();

  void PrintPlanState(const PlanState *plan_state) const;

  planner::AbstractPlanNode *TransformPlan(const PlanState *plan_state);

 private:

  static planner::AbstractPlanNode *TransformModifyTable(const ModifyTableState *plan_state);

  static planner::AbstractPlanNode *TransformInsert(const ModifyTableState *plan_state);

};

} // namespace bridge
} // namespace peloton