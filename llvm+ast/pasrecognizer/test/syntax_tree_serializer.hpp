
#ifndef _PAS_TEST_SYNTAX_TREE_SERIALIZER_
#define _PAS_TEST_SYNTAX_TREE_SERIALIZER_

#include <pasrecognizer/syntax_tree.h>

namespace pas_recognizer
{
    namespace syntax_tree
    {

        std::string relop_name_map[] = {"equal", "non_equal", "less", "less_equal", "greater", "greater_equal"};
        std::string binop_name_map[] = {"plus", "minus", "multiply", "divide", "modulo", "or_", "div", "and_"};
        std::string unaryop_name_map[] = {"plus", "minus", "not_"};

        template <typename Writer>
        class syntax_tree_serializer : public syntax_tree_visitor
        {
        public:
            syntax_tree_serializer(Writer &w) : writer(w) {}

            void serialize(syntax_tree_node &tree)
            {
                tree.accept(*this);
            }

            virtual void visit(assembly &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("assembly");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("global_defs");
                writer.StartArray();
                for (auto def : tree.global_defs)
                    def->accept(*this);
                writer.EndArray();
                writer.EndObject();
            }

            virtual void visit(func_def_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("func_def_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("name");
                writer.String(tree.name.c_str());
                if (tree.ret_type != "")
                {
                    writer.Key("ret_type");
                    writer.String(tree.ret_type.c_str());
                }
                if (tree.para_de.size() > 0)
                {
                    writer.Key("para_de");
                    writer.StartArray();
                    for (auto init : tree.para_de)
                        init->accept(*this);
                    writer.EndArray();
                }
                if (tree.local_var_de.size() > 0)
                {
                    writer.Key("local_var_de");
                    writer.StartArray();
                    for (auto init : tree.local_var_de)
                        init->accept(*this);
                    writer.EndArray();
                }

                writer.Key("body");
                tree.body->accept(*this);
                writer.EndObject();
            }
            virtual void visit(para_de_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("para_de_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);

                writer.Key("name");
                writer.String(tree.name.c_str());
                writer.Key("type");
                writer.String(tree.type.c_str());

                writer.EndObject();
            }

            virtual void visit(cond_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("cond_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("op");
                writer.String(relop_name_map[int(tree.op)].c_str());
                writer.Key("lhs");
                tree.lhs->accept(*this);
                writer.Key("rhs");
                tree.rhs->accept(*this);
                writer.EndObject();
            }

            virtual void visit(binop_expr_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("binop_expr_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("op");
                writer.String(binop_name_map[int(tree.op)].c_str());
                writer.Key("lhs");
                tree.lhs->accept(*this);
                writer.Key("rhs");
                tree.rhs->accept(*this);
                writer.EndObject();
            }

            virtual void visit(unaryop_expr_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("unaryop_expr_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("op");
                writer.String(unaryop_name_map[int(tree.op)].c_str());
                writer.Key("rhs");
                tree.rhs->accept(*this);
                writer.EndObject();
            }

            virtual void visit(lval_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("lval_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("name");
                writer.String(tree.name.c_str());
                if (tree.array_index)
                {
                    writer.Key("array_index");
                    tree.array_index->accept(*this);
                }
                // ptr_list<id_varpart_syntax>id_varpart;
                if (tree.id_varpart.size() > 0)
                {
                    writer.Key("id_varpart");
                    writer.StartArray();
                    for (auto init : tree.id_varpart)
                        init->accept(*this);
                    writer.EndArray();
                }
                if (tree.expression_list.size() > 0)
                {
                    writer.Key("expression_list");
                    writer.StartArray();
                    for (auto init : tree.expression_list)
                        init->accept(*this);
                    writer.EndArray();
                }
                //
                writer.EndObject();
            }
            virtual void visit(id_varpart_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("id_varpart_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);

                if (tree.spot_id != "")
                {
                    writer.Key("spot_id");
                    writer.String(tree.spot_id.c_str());
                }
                if (tree.expression_list.size() > 0)
                {
                    writer.Key("expression_list");
                    writer.StartArray();
                    for (auto init : tree.expression_list)
                        init->accept(*this);
                    writer.EndArray();
                }

                writer.EndObject();
            }

            virtual void visit(literal_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("literal_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("is_int");
                writer.Bool(tree.is_int);
                writer.Key("value");
                if (tree.is_int)
                    writer.Int(tree.intConst);
                else
                    writer.Double(tree.floatConst);

                writer.EndObject();
            }

            virtual void visit(var_def_stmt_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("var_def_stmt_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("is_const");
                writer.Bool(tree.is_constant);
                // writer.Key("is_int");
                // writer.Bool(tree.is_int);

                writer.Key("name");
                writer.String(tree.name.c_str());
                if (tree.const_value)
                {
                    writer.Key("const_value");
                    tree.const_value->accept(*this);
                }
                // writer.Key("var_type");
                // writer.String(tree.type.c_str());
                if (tree.var_type)
                {
                    writer.Key("var_type");
                    tree.var_type->accept(*this);
                }
                if (tree.array_length)
                {
                    writer.Key("array_length");
                    tree.array_length->accept(*this);
                    writer.Key("array_initializers");
                    writer.StartArray();
                    for (auto init : tree.initializers)
                        init->accept(*this);
                    writer.EndArray();
                }
                else if (tree.initializers.size() > 0)
                {
                    writer.Key("vardef_initializer");
                    tree.initializers[0]->accept(*this);
                }
                writer.EndObject();
            }
            virtual void visit(type_def_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("type_def_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("var_type");
                writer.String(tree.var_type.c_str());

                if (tree.array)
                {
                    writer.Key("array");
                    tree.array->accept(*this);
                }

                if (tree.record)
                {
                    writer.Key("record");
                    tree.record->accept(*this);
                }

                writer.EndObject();
            }
            virtual void visit(record_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("record_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);

                if (tree.var_de.size() > 0)
                {
                    writer.Key("var_de");
                    writer.StartArray();
                    for (auto init : tree.var_de)
                        init->accept(*this);
                    writer.EndArray();
                }
                writer.EndObject();
            }
            virtual void visit(array_type_def_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("array_type_def_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);

                if (tree.array_type)
                {
                    writer.Key("array_type");
                    tree.array_type->accept(*this);
                }
                if (tree.period.size() > 0)
                {
                    writer.Key("period");
                    writer.StartArray();
                    for (auto init : tree.period)
                        init->accept(*this);
                    writer.EndArray();
                }

                writer.EndObject();
            }
            virtual void visit(period_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("period_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                if (tree.start)
                {
                    writer.Key("start");
                    tree.start->accept(*this);
                }
                if (tree.end)
                {
                    writer.Key("end");
                    tree.end->accept(*this);
                }

                writer.EndObject();
            }

            virtual void visit(const_var_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("const_var_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);

                if (tree.flag != "")
                {
                    writer.Key("flag");
                    writer.String(tree.flag.c_str());
                }
                if (tree.id != "")
                {
                    writer.Key("id");
                    writer.String(tree.id.c_str());
                }
                if (tree.num)
                {
                    writer.Key("num");
                    tree.num->accept(*this);
                }
                if (tree.letter != "")
                {
                    writer.Key("letter");
                    writer.String(tree.letter.c_str());
                }

                writer.EndObject();
            }

            //
            virtual void visit(assign_stmt_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("assign_stmt_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("target");
                tree.target->accept(*this);
                writer.Key("value");
                tree.value->accept(*this);
                writer.EndObject();
            }

            virtual void visit(func_call_stmt_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("func_call_stmt_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("name");
                writer.String(tree.name.c_str());
                writer.EndObject();
            }

            virtual void visit(block_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("block_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("body");
                writer.StartArray();
                for (auto stmt : tree.body)
                    stmt->accept(*this);
                writer.EndArray();
                writer.EndObject();
            }

            virtual void visit(if_stmt_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("if_stmt_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("pred");
                tree.pred->accept(*this);
                writer.Key("thenbody");
                tree.then_body->accept(*this);
                if (tree.else_body)
                {
                    writer.Key("elsebody");
                    tree.else_body->accept(*this);
                }
                writer.EndObject();
            }

            virtual void visit(while_stmt_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("while_stmt_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.Key("pred");
                tree.pred->accept(*this);
                writer.Key("body");
                tree.body->accept(*this);
                writer.EndObject();
            }

            virtual void visit(empty_stmt_syntax &tree) override
            {
                writer.StartObject();
                writer.Key("type");
                writer.String("empty_stmt_syntax");
                writer.Key("line");
                writer.Int(tree.line);
                writer.Key("pos");
                writer.Int(tree.pos);
                writer.EndObject();
            }

        private:
            Writer &writer;
        };
    }
}

#endif
