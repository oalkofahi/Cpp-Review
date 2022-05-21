.PHONY: clean All

All:
	@echo "----------Building project:[ Stateless_Lambda_Expressions - Debug ]----------"
	@cd "Stateless_Lambda_Expressions" && "$(MAKE)" -f  "Stateless_Lambda_Expressions.mk"
clean:
	@echo "----------Cleaning project:[ Stateless_Lambda_Expressions - Debug ]----------"
	@cd "Stateless_Lambda_Expressions" && "$(MAKE)" -f  "Stateless_Lambda_Expressions.mk" clean
