.PHONY: clean All

All:
	@echo "----------Building project:[ Stateful_Lambda_Expressions - Debug ]----------"
	@cd "Stateful_Lambda_Expressions" && "$(MAKE)" -f  "Stateful_Lambda_Expressions.mk"
clean:
	@echo "----------Cleaning project:[ Stateful_Lambda_Expressions - Debug ]----------"
	@cd "Stateful_Lambda_Expressions" && "$(MAKE)" -f  "Stateful_Lambda_Expressions.mk" clean
