/*
 * UnknownWordPenalty.h
 *
 *  Created on: 28 Oct 2015
 *      Author: hieu
 */

#pragma once

#include "PhraseTable.h"

namespace Moses2
{

class UnknownWordPenalty: public PhraseTable
{
public:
  UnknownWordPenalty(size_t startInd, const std::string &line);
  virtual ~UnknownWordPenalty();

  void Lookup(const Manager &mgr, InputPathsBase &inputPaths) const;
  virtual TargetPhrases *Lookup(const Manager &mgr, MemPool &pool,
      InputPathBase &inputPath) const;

  virtual void
  EvaluateInIsolation(const System &system, const Phrase &source,
      const TargetPhrase &targetPhrase, Scores &scores,
      SCORE *estimatedScore) const;

  virtual void InitActiveChart(SCFG::InputPath &path) const;
  void Lookup(MemPool &pool,
      const System &system,
      const SCFG::Stacks &stacks,
      SCFG::InputPath &path) const;

};

}

