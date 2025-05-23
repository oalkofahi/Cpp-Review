.PHONY: clean All

All:
	@echo "----------Building project:[ Practice - Debug ]----------"
	@cd "practice" && "$(MAKE)" -f  "Practice.mk"
clean:
	@echo "----------Cleaning project:[ Practice - Debug ]----------"
	@cd "practice" && "$(MAKE)" -f  "Practice.mk" clean
