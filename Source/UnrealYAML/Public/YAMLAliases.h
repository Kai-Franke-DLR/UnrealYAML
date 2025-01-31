﻿#pragma once

#include "yaml.h"

/** Possible Types a Node can have:
 *  - Undefined: Invalid Node
 *  - Null: Node has no Content
 *  - Scalar: Node is Storing a single Value
 *  - Sequence: Node is a List
 *  - Map: Node is Storing Key-Value pairs. */
using EYamlNodeType = YAML::NodeType::value;

// Emitter --------------------------------------------------------------------------------------------

/** An Emitter used to create new YAML-Structures. You can use the "<<"-operator to add Elements to the Structure. */
using FYamlEmitter = YAML::Emitter;

using EYamlEmitterStyle = YAML::EmitterStyle::value;

/** Use these to begin a Sequence or create Map Key-Value pairs */
using EYamlEmitterTags = YAML::EMITTER_MANIP;


// Iteration ------------------------------------------------------------------------------------------
using FYamlConstIterator = YAML::const_iterator;
using FYamlIterator = YAML::iterator;